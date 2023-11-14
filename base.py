#!/usr/bin/python3
""" Module for Base class """
import unittest
from models.square import Square
from models.base import Base
from io import StringIO
from models.rectangle import Rectangle
from unittest import TestCase
from unittest.mock import patch


class TestBase(unittest.TestCase):
    """ Functions to test Base class """

    def setUp(self):
        """ Method invoked for each test """
        Base._Base__nb_objects = 0

    def test_id(self):
        """ Testing the assigned id """
        n = Base(1)
        self.assertEqual(n.id, 1)

    def test_id_default(self):
        """ Testing default id """
        n = Base()
        self.assertEqual(n.id, 1)

    def test_id_nb_objects(self):
        """ Testing nb object attribute """
        n = Base()
        n2 = Base()
        n3 = Base()
        self.assertEqual(n.id, 1)
        self.assertEqual(n2.id, 2)
        self.assertEqual(n3.id, 3)

    def test_id_mix(self):
        """ Testing nb object attributes and assigned id """
        n = Base()
        n2 = Base(1024)
        n3 = Base()
        self.assertEqual(n.id, 1)
        self.assertEqual(n2.id, 1024)
        self.assertEqual(n3.id, 2)

    def test_string_id(self):
        """ Testing string id """
        n = Base('1')
        self.assertEqual(n.id, '1')

    def test_more_args_id(self):
        """ Testing passing more arguments to init method """
        with self.assertRaises(TypeError):
            n = Base(1, 1)

    def test_access_private_attrs(self):
        """ Testing accessing to private attributes """
        n = Base()
        with self.assertRaises(AttributeError):
            n.__nb_objects

    def test_save_to_file_1(self):
        """ Testing JSON file """
        Square.save_to_file(None)
        s = "[]\n"
        with open("Square.json", "r") as file:
            with patch('sys.stdout', n=StringIO()) as str_out:
                print(file.read())
                self.assertEqual(str_out.getvalue(), s)

        try:
            os.remove("Square.json")
        except:
            pass

        Square.save_to_file([])
        with open("Square.json", "r") as file:
            self.assertEqual(file.read(), "[]")

    def test_save_to_file_2(self):
        """ Testing JSON file """
        Rectangle.save_to_file(None)
        s = "[]\n"
        with open("Rectangle.json", "r") as file:
            with patch('sys.stdout', n=StringIO()) as str_out:
                print(file.read())
                self.assertEqual(str_out.getvalue(), s)
        try:
            os.remove("Rectangle.json")
        except:
            pass

        Rectangle.save_to_file([])
        with open("Rectangle.json", "r") as file:
            self.assertEqual(file.read(), "[]")
