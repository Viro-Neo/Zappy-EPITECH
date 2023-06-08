import unittest
import sys
import io
from commands.get_server_response_for_commands import check_response
from client import Client

class TestResponseChecker(unittest.TestCase):

    def test_unknown(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Forward")

        test_response = "ko"
        expected = "invalid"
        self.assertEqual(check_response(test_response, client), expected)

    def test_movement_response(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Forward")

        test_response = "ok"
        expected = "good"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_connect_number_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Forward")
        client.cmd_buff.append("Connect_nbr")

        test_response = "53"
        expected = "good"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_connect_number_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Forward")
        client.cmd_buff.append("Connect_nbr")

        test_response = "a"
        expected = "invalid"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_eject_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Eject")

        test_response = "ok"
        expected = "good"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_eject_response_correct2(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Eject")

        test_response = "ko"
        expected = "good"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_eject_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Eject")

        test_response = "asd"
        expected = "invalid"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_incantation_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Incantation")

        test_response = "Elevation underway Current level: 5"
        expected = "good"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_incantation_response_correct2(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Incantation")

        test_response = "ko"
        expected = "good"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_incantation_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Incantation")

        test_response = "Elevation underway Current level: 9"
        expected = "invalid"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_look_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Look")

        test_response = "[food, limestone food, player,,player food, test]"
        expected = "good"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_look_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Look")

        test_response = "ok"
        expected = "invalid"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_inventory_response_correct(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Inventory")

        test_response = "[food 4, limestone 2]"
        expected = "good"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_inventory_response_incorrect(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Inventory")

        test_response = "ok"
        expected = "invalid"
        self.assertEqual(check_response(test_response, client), expected)
    
    def test_inventory_response_incorrect2(self):
        client = Client(1234, "A", "test")
        client.cmd_buff.append("Connect_nbr")
        client.cmd_buff.append("Inventory")

        test_response = "[food 4, limestone, test 12]"
        expected = "invalid"
        self.assertEqual(check_response(test_response, client), expected)

if __name__ == '__main__':
    unittest.main()
