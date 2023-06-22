"""
    Calling
    $python setup.py build_ext --inplace
    will build the extension library in the current file.
"""

from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension(
            name="testcython.ctest",
            sources=[
                "src/testcython/ctest.pyx",
                "src/csrc/Test.cpp",
            ],
            language="c++",
            include_dirs=["testcython"],
            extra_compile_args=[
                "-std=c++17",
            ],
        ),
    ]
)
