<?php
  fscanf(STDIN,"%d",$n);
  $arr = array();
  $res=array();
  for($i=0;$i<$n;$i++)
  {
    fscanf(STDIN,"%s",$str);
    if(array_key_exists($str,$arr))
    {
      $res[]=$str.$arr[$str];
      $arr[$str]++;

    }
    else {
      $arr[$str]=1;
      $res[]="OK";
    }
  }
  for($i=0;$i<$n;$i++)
    echo $res[$i]."\n";

?>
