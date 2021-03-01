#!/usr/bin/env python3

import unittest
import sys
import os
import subprocess

tests = [
    [
        [
            "mkdir -p tmp",
            "cd tmp",
        ],
        [
            "pwd >>",
            "ls /home/namig >> ",
            "echo 'Hello, World !!!' >>",
        ]
    ]
]

minishell = subprocess.Popen(['./minishell'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

class TestStringMethods(unittest.TestCase):

  def test1(self):

    file_minishell = "minishell_test"
    file_shell = "shell_test"
    v_comm = ""

    for commands in tests[0][0]:
        v_comm += commands  + ';'

    for commands in tests[0][1]:
        v_comm += commands + file_shell + ';'

    os.system(v_comm)

    v_comm = ""
    for commands in tests[0][0]:
        v_comm += commands  + ';'

    for commands in tests[0][1]:
        v_comm += commands + file_minishell + ';'
    
    minishell.communicate(input=v_comm.encode()) 

    
    f1 = open("tmp/" + file_minishell, 'r')
    f2 = open("tmp/" + file_shell, 'r')

    os.system("rm -rf tmp/")

    self.assertEqual(f1.read(), f2.read())

    f1.close()
    f2.close()

    

if __name__ == "__main__":
    unittest.main()
