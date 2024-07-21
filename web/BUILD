cc_binary(
    name = "trundle-web",
    srcs = ["main.cc", "db.cc", "db.hh"],
    deps = ["@cpp-httplib//:httplib", "@sqlite3//:sqlite3", "//console:trundle-console"],
    copts = ['-std=c++20']
)