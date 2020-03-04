from unittest import TestCase
import transport as tr

class TestBalance_condition(TestCase):

    def test_balance_condition_true(self):
        a = [130, 75, 65, 60, 75, 60]
        b = [130, 55, 80, 65, 135]
        self.assertTrue(tr.balance_condition(a, b))

    def test_balance_condition_false(self):
        a = [130, 75, 65, 60, 75, 60]
        b = [130, 55, 70, 65, 135]
        self.assertFalse(tr.balance_condition(a, b))
