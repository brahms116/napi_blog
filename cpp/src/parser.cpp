#include "../include/JsonPrimitive.hpp"
#include "../include/JsonValuePair.hpp"
#include "../include/JsonNode.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>


struct BlogData{
    std::string title;
    std::string description;
    std::string src;
    std::vector<std::string> paragraphs;
};

std::string parsefile(int timestamp,const char* path){

    
        /* code */
    
    //read data
    BlogData blogData;
    std::string line;
    std::ifstream myfile (path);
    if(myfile.is_open()){
       
        //title
        std::getline(myfile,line);
        if(line.compare(0,6,"TITLE:")!=0 || line.size()<6  ){
            return "";
        }
        blogData.title = line.substr(6);

        //description
        std::getline(myfile,line);
        if(line.compare(0,12,"DESCRIPTION:")!=0 || line.size()<12  ){
            return "";
        }
        blogData.description = line.substr(12);

        //image src
        std::getline(myfile,line);
        if(line.compare(0,4,"SRC:")!=0 || line.size()<4  ){
            return "";
        }
        blogData.src = line.substr(4);

        //check empty line
        std::getline(myfile,line);
        if(line!="")
            return "";

        std::string tempPara = "";
        while(std::getline(myfile,line)){
            if(line=="" && tempPara!=""){
                blogData.paragraphs.emplace_back(tempPara);
                tempPara="";
            }else if(line!=""){
                tempPara+=line;
            }
        }
        if(tempPara!=""){
            blogData.paragraphs.emplace_back(tempPara);
        }
        myfile.close();
        
    
    }else{
        return "";
    }

    JsonObject obj;
    std::shared_ptr<JsonValuePair> title = std::make_shared<JsonValuePair>(
        "title",
        std::make_shared<JsonPrimitive>(
            blogData.title
        )
    );
    std::shared_ptr<JsonValuePair> description = std::make_shared<JsonValuePair>(
        "description",
        std::make_shared<JsonPrimitive>(
            blogData.description
        )
    );
    std::shared_ptr<JsonValuePair> src = std::make_shared<JsonValuePair>(
        "src",
        std::make_shared<JsonPrimitive>(
            blogData.src
        )
    );
    
    std::shared_ptr<JsonValuePair> ts = std::make_shared<JsonValuePair>(
        "createdAt",
        std::make_shared<JsonPrimitive>(
            timestamp
        )
    );
    
    obj.addChild(title);
    obj.addChild(description);
    obj.addChild(src);
    obj.addChild(ts);

    std::shared_ptr<JsonArray> paragraphs = std::make_shared<JsonArray>();

    for(const std::string para : blogData.paragraphs){
        paragraphs->addChild(std::make_shared<JsonPrimitive>(para));
    }

    std::shared_ptr<JsonValuePair> para = std::make_shared<JsonValuePair>(
        "para",
        paragraphs
    );

    obj.addChild(para);

    return obj.getString();

    
    
    
}
