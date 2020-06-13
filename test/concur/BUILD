load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "thread-test",
    srcs = glob(["*.cc"]),
    copts = ["-Iinclude"],
    deps = [
        "//include/blaze/concur:thread_api",
        "//include/blaze/concur:scheduler_api",
        "//src/concur:thread",
        "//include/blaze/posix:thread_api",
        "//src/posix:thread",
        "@gtest//:gtest_main",
    ],
)