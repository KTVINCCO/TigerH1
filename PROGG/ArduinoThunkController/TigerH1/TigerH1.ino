

String Command = "";





void setup() 
{
  //Ходовая
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  //Стрельба
  pinMode(8,OUTPUT);
  digitalWrite(8, LOW);

  //Башня
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(9, 0);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);


  //Блютуз
  Serial1.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}





void loop() 
{
  UpdateSerial();
}





String CommandCharInp = "";
String CommandCharInpDecoded = "";
//String Command = ""; // In top
int CommandStatus = 0;
String LastCommandDecodedChar = "";

void UpdateSerial()
{
  CommandCharInp = String(Serial1.read());
  if(CommandCharInp != "-1")
  {
    CommandCharInpDecoded = DecodeInput(CommandCharInp);
    Serial.println("");
    Serial.println(CommandCharInpDecoded);  

    if(CommandCharInpDecoded != LastCommandDecodedChar)
    {
      LastCommandDecodedChar = CommandCharInpDecoded;

      //Начать записывать новый код комманды
      if(CommandCharInpDecoded == "1")
      {
        Command = "";
        CommandStatus = 1;
      }

      //Записать символ в код
      if(CommandStatus == 1 && ( CommandCharInpDecoded != "1" && CommandCharInpDecoded != "2" ) )
      {
        Command += CommandCharInpDecoded;
      }

      //Использовать команду
      if(CommandStatus == 1 && CommandCharInpDecoded == "2")
      {
        RunCommand(Command);
      }      
    }
  }
}





void RunCommand(String Command)
{
  switch (Command.toInt()) 
  {
    case 34:
      Serial.println("Forward!");
    break;
    case 35:
      Serial.println("Backward!");
    break;
    case 36:
      Serial.println("ToLeft!");
    break;
    case 37:
      Serial.println("ToRight!");
    break;
    case 38:
      Serial.println("TowerToLeft!");
    break;
    case 39:
      Serial.println("TowerToRight!");
    break;
    case 43:
      Serial.println("Fire!");
    break;
    case 45:
      Serial.println("StopAll!");
    break;
  }
}
