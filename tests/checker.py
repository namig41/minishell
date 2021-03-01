#!/usr/bin/env python3

import unittest
import argparse
import sys
import os
import subprocess

minishell = subprocess.Popen(['../minishell'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

class TestStringMethods(unittest.TestCase):

  def test1(self):

    s_minishell = "minishell_test1"
    s_shell = "shell_test1"

    for commands in tests[0]:
        os.system(commands + s_shell)
        minishell.communicate(input=(commands + s_minishell).encode()) 

    

  def test2(self):
      pass

  def test3(self):
      pass

tests = [
[
"ls >>",
],
[
"touch \"my file with whitespaces in name.txt\"",
"ls",
"echo '123 456 \" str \"'",
"echo '123 456 \" str \"' > \"my file with whitespaces in name.txt\"",
"cat my\\ file\\ with\\ whitespaces\\ in\\ name.txt",
"echo \"test\" >> \"my file with whitespaces in name.txt\"",
"cat \"my file with whitespaces in name.txt\"",
"echo 'truncate' > \"my file with whitespaces in name.txt\"",
"cat \"my file with whitespaces in name.txt\"",
"echo \"test 'test'' \\\\\" >> \"my file with whitespaces in name.txt\"",
"cat \"my file with whitespaces in name.txt\""
],
[
"# Comment",
"echo 123\\\n456",
],
[
"rm my\\ file\\ with\\ whitespaces\\ in\\ name.txt",
"echo 123 | grep 2",
"echo 123\\\n456\\\n| grep 2",
"echo \"123\n456\n7\n\" | grep 4",
"echo 'source string' | sed 's/source/destination/g'",
"echo 'source string' | sed 's/source/destination/g' | sed 's/string/value/g'",
"echo 'source string' |\\\nsed 's/source/destination/g'\\\n| sed 's/string/value/g'",
"echo 'test' | exit 123 | grep 'test2'",
"echo 'source string' | sed 's/source/destination/g' | sed 's/string/value/g' > result.txt",
"cat result.txt",
],
[
"false && echo 123",
"true && echo 123",
"true || false && echo 123",
"true || false || true && echo 123",
"false || echo 123"
],
[
"sleep 0.5 && echo 'back sleep is done' &",
"echo 'next sleep is done'",
"sleep 0.5"
]
]


if __name__ == "__main__":
    unittest.main()
