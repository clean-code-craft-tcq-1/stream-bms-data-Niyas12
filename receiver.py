"""
Created on Thu May 27 10:31:35 2021

@author: EPA5COB

"""

import sys
import json
from Predefined_values import limit
    
def Form_Receiver_input_and_Perform_Operation():
    
    list_temp =[]
    list_soc =[]
    
    for i in sys.stdin:
        bms_param = json.loads(i) #creates a dictinary out of 'i'
        for key, value in bms_param.items():
            if key in limit.keys():
                if key == 'Temperature':
                    list_temp.append(bms_param[key])
                if key == 'SOC':    
                    list_soc.append(bms_param[key])
            else:
                print("Not a valid battery parameter")
                
    Operations_on_input_and_print_on_console(list_temp,list_soc)       
       
def Operations_on_input_and_print_on_console(list_temp,list_soc):
    
    print("-----------------Temperature----------------")
    print(list_temp)
    print("--------------------------------------------")
    print("---------------------SOC--------------------")
    print(list_soc)
    print("--------------------------------------------")
        
    print("Max_Temp: ",calculate_max_temp(list_temp),"  Min_Temp: ",calculate_min_temp(list_temp))
    print("Max_SOC:  ",calculate_max_soc(list_soc),"  Min_SOC:  ",calculate_min_soc(list_soc))
    
    print("Average of last 5 values of Temp and SOC respectively: ",calculate_avg_temp_soc(list_temp,list_soc))
   

def calculate_max_temp(list_temp):
    return max(list_temp)
      
def calculate_min_temp(list_temp):
    return min(list_temp) 

def calculate_max_soc(list_soc):
    return max(list_soc)  

def calculate_min_soc(list_soc):
    return min(list_soc)

def calculate_avg_temp_soc(list_temp,list_soc):
    
    length = len(list_temp)
    sum_temp = 0
    sum_soc = 0
    
    if length !=0:
        for i in range(-1,-6,-1):
            sum_temp += list_temp[i]
            sum_soc += list_soc[i]
    
        return sum_temp/5,sum_soc/5
    else:
        return "Length of the list is Zero"
    
    

    
    
    
     
    
