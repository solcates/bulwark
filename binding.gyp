{
    "variables": {
        "node_addon": '<!(node -p -e "require(\'path\').dirname(require.resolve(\'addon-layer\'))")',
    },
    "targets": [
        {
            "target_name": "shim",
            "dependencies": ["<(node_addon)/binding.gyp:addon-layer", ],
            "include_dirs": ["<(node_addon)/include", "deps/rsa"],
            "sources": [
                "src/session.c",
                "src/bulwark.c",
            ],
        },
    ],
}
