#!/usr/bin/sh

mkdir test/test_source
touch test/test_source/{a..z}.txt

if [ -d test/test_db ]
then
  exit
fi

ftrcreate test/test_source test/test_db