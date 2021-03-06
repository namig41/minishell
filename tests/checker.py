#!/usr/bin/env python3

import unittest
import os
import subprocess
from random import choice, randint

COMMANDS = [
    "pwd",
    "ls /",
    "ip a",
    "uname -a",
]

TEXT_ARRAY = "Lorem Ipsum is simply dummy text of the printing and typesetting industry"

CREATE_TMP = "mkdir -p tmp; cd tmp; touch "
MINISHELL_FILE_NAME = "tmp_minishell"
SHELL_FILE_NAME = "tmp_shell"

class TestMinishell(unittest.TestCase):
    def test_base_command100(self):
        minishell_commands = CREATE_TMP + MINISHELL_FILE_NAME + ';'
        shell_commands = CREATE_TMP + SHELL_FILE_NAME + ';'
        minishell = subprocess.Popen(['./minishell'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

        for i in range(10):
            rand_command = choice(COMMANDS)
            minishell_commands += "{} >> {};".format(rand_command, MINISHELL_FILE_NAME)
            shell_commands += "{} >> {};".format(rand_command, SHELL_FILE_NAME)

        os.system(shell_commands)
        minishell.communicate(input=minishell_commands.encode())

        f1 = open("tmp/" + MINISHELL_FILE_NAME, 'r')
        f2 = open("tmp/" + SHELL_FILE_NAME, 'r')

        self.assertEqual(f1.read(), f2.read())

        f1.close()
        f2.close()
        os.system("rm -rf tmp")

    def test_echo_command100(self):
        minishell_commands = CREATE_TMP + MINISHELL_FILE_NAME + ';'
        shell_commands = CREATE_TMP + SHELL_FILE_NAME + ';'
        minishell = subprocess.Popen(['./minishell'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

        for i in range(10):
            rand_word = TEXT_ARRAY[:randint(2, len(TEXT_ARRAY))]
            minishell_commands += "echo {} >> {};".format(rand_word, MINISHELL_FILE_NAME)
            shell_commands += "echo {} >> {};".format(rand_word, SHELL_FILE_NAME)

        os.system(shell_commands)
        minishell.communicate(minishell_commands.encode())

        f1 = open("tmp/" + MINISHELL_FILE_NAME, 'r')
        f2 = open("tmp/" + SHELL_FILE_NAME, 'r')

        self.assertEqual(f1.read(), f2.read())

        f1.close()
        f2.close()
        os.system("rm -rf tmp")

if __name__ == "__main__":
    unittest.main()
