from unittest import TestCase
import transport as tr

class TestMethod_min_element(TestCase):
    def test_method_min_element(self):
        a = [140, 160, 120]
        b = [150, 90, 100, 80]
        c = [[2, 3, 4, 2],
             [8, 4, 1, 4],
             [9, 7, 3, 6]]
        r = [[140, 0, 0, 0],
             [0, 60, 100, 0],
             [10, 30, 0, 80]]
        self.assertEqual(r, tr.method_min_element(a, b, c))
