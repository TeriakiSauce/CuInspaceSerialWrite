def write_to_ground_station(command_string): 
    """writes data to the ground station via UART
       author: Tarik
       @param command_string: full command to be send to the ground station
       @param COM_PORT: the COM port to be used for the UART transmission
       
       Ex. 
       >>write_to_ground_station("radio set pwr 7", COM1)
       >>"ok"
       
       //above example sets the radio tramission power to 7 using COM1
       
       """
    ser = init_serial_port("COM")
    
    data = str(command_string) 
    
    #must include carriage return for valid commands (see DS40001784B pg XX)
    data = data + "\r\n"
    
    # encode command_string as bytes and then transmit over serial port
    ser.write(data.encode('utf-8'))  
    
    #if ground station produces error in response to command then it will 
    #halt the program 
    wait_for_ok()
    
    return 0
