#!/usr/bin/sh
EXIT=0
function assert
{
  if [ $? -ne 0 ]
  then
    echo $@
    EXIT=1
  fi
}
cd test_db
echo ".exit" | ../../ftrq
assert .exit
echo ".echo 123" | ../../ftrq
assert .echo 123
exit $EXIT