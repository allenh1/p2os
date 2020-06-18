# Copyright 2018 Hunter L. Allen
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import argparse
import os
import sys

from docker.errors import ContainerError
from superflore.docker import Docker
from superflore.utils import err
from superflore.utils import info
from superflore.utils import ok


repo_location="/tmp/repo"

def set_up_container():
    d = Docker()
    curr = os.getcwd()
    try:
        d.pull('allenh1', 'asw_test_env')
    except:
        d.build(os.path.realpath("../docker/Dockerfile"))
    info("Using repo in directory '%s'" % os.path.realpath(".."))
    d.map_directory(os.path.realpath(".."), repo_location)
    return d


def test_ament_uncrustify(container, subdir, auto_fix=False, verbose=False):
    container.add_bash_command('cd %s/%s' % (repo_location, subdir))
    container.add_bash_command('source /opt/ros/dashing/setup.bash')
    fix = ''
    if auto_fix:
        fix = "--reformat "
    container.add_bash_command('ament_uncrustify %ssrc include test' % fix)
    try:
        container.run(show_cmd=False)
        if verbose:
            print(container.log)
    except ContainerError:
        print(container.log)
        container.log = None
        return 1
    container.clear_commands()
    container.log = None
    return 0


def test_ament_cppcheck(container, subdir, verbose=False):
    container.add_bash_command('cd %s/%s' % (repo_location, subdir))
    container.add_bash_command('source /opt/ros/dashing/setup.bash')
    container.add_bash_command('ament_cppcheck src include test')
    try:
        container.run(show_cmd=verbose)
        if verbose:
            print(container.log)
    except ContainerError:
        print(container.log)
        container.log = None
        return 1
    container.clear_commands()
    container.log = None
    return 0


def test_ament_cpplint(container, subdir, verbose=False):
    container.add_bash_command('cd %s/%s' % (repo_location, subdir))
    container.add_bash_command('source /opt/ros/dashing/setup.bash')
    container.add_bash_command('ament_cpplint src include test')
    try:
        container.run(show_cmd=verbose)
        if verbose:
            print(container.log)
    except ContainerError:
        print(container.log)
        container.log = None
        return 1
    container.clear_commands()
    container.log = None
    return 0


def main(argv):
    argv = argv[1:]
    parser = argparse.ArgumentParser('ASW Docker Test Runner')
    parser.add_argument(
        '--fix-style',
        help='automatically fix the code style',
        action="store_true"
    )
    parser.add_argument(
        '--verbose',
        help="verbose output",
        action="store_true"
    )
    args = parser.parse_args(argv)
    d = set_up_container()
    score = test_ament_uncrustify(d, 'p2os_driver', args.fix_style)
    score += test_ament_cppcheck(d, 'p2os_driver')
    score += test_ament_cpplint(d, 'p2os_driver')
    return score


if __name__ == '__main__':
    sys.exit(main(sys.argv))
