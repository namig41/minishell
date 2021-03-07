#!/usr/bin/env python3

import unittest
import os
import subprocess
from random import choice, randint

NUM_TESTS = 20

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
    def test_base_command(self):
        minishell_commands = CREATE_TMP + MINISHELL_FILE_NAME + ';'
        shell_commands = CREATE_TMP + SHELL_FILE_NAME + ';'
        minishell = subprocess.Popen(['./minishell'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

        for i in range(NUM_TESTS):
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

    def test_echo_command(self):
        minishell_commands = CREATE_TMP + MINISHELL_FILE_NAME + ';'
        shell_commands = CREATE_TMP + SHELL_FILE_NAME + ';'
        minishell = subprocess.Popen(['./minishell'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

        for i in range(NUM_TESTS):
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

    def get_eval_expression(self):
        digit = "123456789"
        op = "+-*/"
        ob = randint(2, 10)
        cb = 0
        exp = ""

        len_exp = randint(1, 10)

        while len_exp:
            num = ""
            for i in range(randint(1, 3)):
                num += choice(digit)

            if (randint(0, 1) and ob > 0):
                exp += "("
                ob -= 1
                cb += 1

            exp += num
            if len_exp > 1:
                exp += choice(op)
            len_exp -= 1

        while cb:
            exp += ")"
            cb -= 1

        return exp

    def test_eval_command(self):
        os.system("mkdir -p tmp;")
        minishell_commands = "cd tmp; touch {}".format(MINISHELL_FILE_NAME)+ MINISHELL_FILE_NAME + ';'
        minishell = subprocess.Popen(['./minishell'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

        with open("tmp/" + SHELL_FILE_NAME, 'w') as f:

            for i in range(NUM_TESTS):
                rand_exp = self.get_eval_expression()
                minishell_commands += "eval {} >> {};".format(rand_exp, MINISHELL_FILE_NAME)
                f.write(str(eval(rand_exp)))

        minishell.communicate(minishell_commands.encode())

        f1 = open("tmp/" + MINISHELL_FILE_NAME, 'r')
        f2 = open("tmp/" + MINISHELL_FILE_NAME, 'r')

        self.assertEqual(f1.read(), f2.read())

        f1.close()
        f2.close()
        os.system("rm -rf tmp")

if __name__ == "__main__":
    unittest.main()
