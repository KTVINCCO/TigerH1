String DecodeInput(String Input)
{
  String Output = "";
  
  switch (Input.toInt()) 
  {
    case 48:
      Output = "0";
    break;
    case 49:
      Output = "1";
    break;
    case 50:
      Output = "2";
    break;
    case 51:
      Output = "3";
    break;
    case 52:
      Output = "4";
    break;
    case 53:
      Output = "5";
    break;
    case 54:
      Output = "6";
    break;
    case 55:
      Output = "7";
    break;
    case 56:
      Output = "8";
    break;
    case 57:
      Output = "9";
    break;
  }

  return(Output);
}
