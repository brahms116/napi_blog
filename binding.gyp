{
    "targets":[{
        "target_name":"BlogParser",
        "sources":[
            "cpp/src/main.cpp"
        ],
        "include_dirs":[
            "<!(node -p \"require('node-addon-api').include_dir\")",
            "cpp/include"
        ],
        "defines":[
            "NAPI_DISABLE_CPP_EXCEPTIONS"
        ]
    }]
}