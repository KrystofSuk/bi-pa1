PROG=C:/Users/sukkr/source/repos/Progtest/$1/prog.exe
TEST=C:/Users/sukkr/source/repos/Progtest/$1/TESTDATA
for IN_FILE in $TEST/*_in.txt
  do    
  REF_FILE=`echo -n $IN_FILE | sed -e 's/_in\(.*\)$/_out_win\1/'`
  $PROG < $IN_FILE > out.txt
  if ! diff $REF_FILE out.txt
  then        
    echo "Fail: $IN_FILE | $REF_FILE";
    exit
  else
    echo "OK $IN_FILE";
  fi
  rm "out.txt"
done