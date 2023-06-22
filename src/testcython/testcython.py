from .ctest import CTest
from ._version import __version__


class TestCython:
    def __init__(self):
        self.test = CTest()

    def test_cython(self):
        X = [[x for x in range(i, i + 3)] for i in range(1, 30, 3)]
        weights = [25 / (i + 1) for i in range(10)]
        labels = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        self.test.fit(X, labels, weights)
        print("Hello from test_cython()!")
        print("My version: ", self.version())
        print("CTest version: ", self.test.get_version().decode("utf-8"))
        self.test.print()

    @staticmethod
    def version():
        return __version__
