load("//build/kernel/kleaf:kernel.bzl", "kernel_module")

def rtl8852be_module(name, kernel_build, deps = None):
    kernel_module(
        name = name,
        srcs = ["//vendor/amlogic/realtek-drivers/8852be:rtl8852be_srcs"],
        makefile = ["//vendor/amlogic/realtek-drivers/8852be:Makefile"],
        deps = deps,
        outs = ["8852be.ko", "rtkm.ko"],
        kernel_build = kernel_build,
    )
