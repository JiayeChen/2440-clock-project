void RTC_Setup(hour_val, min_val,sec_val)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT




    // Configure RTC
    RTCCTL0_H = RTCKEY_H ;                 // Unlock RTC key protected registers
    RTCCTL1 &= ~(RTC_C_CTL13_BCD) ;        //hex output, default hex
   



    RTCHOUR = hour_val;
    RTCMIN = min_val;
    RTCSEC = sec_val;
    //The real-time clock registers are updated once per second.


    RTCCTL1 &= ~(RTCHOLD);                    // Start RTC calendar mode







}
int decimal_to_hex(void)
{
    long int decimalNumber,remainder,quotient;
    int i=1,j,temp;
    char hexadecimalNumber[100];
    printf("Enter any decimal number: ");
    scanf("%ld",&decimalNumber);
    quotient = decimalNumber;
    while(quotient!=0) {
        temp = quotient % 16;
        //To convert integer into character
        if( temp < 10)
                   temp =temp + 48; else
                 temp = temp + 55;
        hexadecimalNumber[i++]= temp;
        quotient = quotient / 16;
    }
    printf("Equivalent hexadecimal value of decimal number %d: ",decimalNumber);
    for (j = i -1 ;j> 0;j--)
          printf("%c",hexadecimalNumber[j]);
    return 0;
}
