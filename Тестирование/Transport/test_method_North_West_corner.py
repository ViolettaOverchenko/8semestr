from unittest import TestCase
import transport as tr

class TestMethod_north_west_corner(TestCase):
    def test_method_north_west_corner(self):
        a = [140, 160, 120]
        b = [150, 90, 100, 80]
        r = [[140, 0, 0, 0],
             [10, 90, 60, 0],
             [0, 0, 40, 80]]
        self.assertEqual(r, tr.method_north_west_corner(a, b))
