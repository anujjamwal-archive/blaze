load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "thread",
  srcs = ["thread.cc"],
  visibility = ["//visibility:public"],
  copts = ["-Iinclude"],
  deps = [
    "//include/blaze/posix:thread_api"
  ]
)