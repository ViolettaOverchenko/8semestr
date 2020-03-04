from unittest import TestCase
import transport as tr

class TestCost(TestCase):
    def test_cost(self):
        c = [[2, 3, 4, 2],
             [8, 4, 1, 4],
             [9, 7, 3, 6]]
        r = [[140, 0, 0, 0],
             [0, 60, 100, 0],
             [10, 30, 0, 80]]
        self.assertEqual(1400, tr.cost(c, r))
