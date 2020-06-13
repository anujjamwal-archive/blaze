load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "thread-test",
    srcs = ["thread_test.cc"],
    copts = ["-Iinclude"],
    deps = [
        "//include/blaze/posix:thread_api",
        "//src/posix:thread",
        "@gtest//:gtest_main",
    ],
)