# -*- coding: utf-8 -*-
"""
Created on Wed May 26 16:00:42 2021

@author: EPA5COB
"""
import unittest
import receiver

class ReceiverTest(unittest.TestCase):
    
    def testSenderOutput(self):
        receiver.Form_Receiver_input_and_Perform_Operation()
     
    def testMinTemp(self):
        self.assertTrue(receiver.calculate_min_temp([20,19,10,15,18,90,60,80,70,50]) == 10)
        
    def testMaxTemp(self):
        self.assertTrue(receiver.calculate_max_temp([20,19,10,15,18,90,60,80,70,50]) == 90)  
        
    def testMinSOC(self):
        self.assertTrue(receiver.calculate_min_soc([70,40,20,99,90,98,88,77,66,55]) == 20)
    
    def testMaxSOC(self):
        self.assertTrue(receiver.calculate_max_soc([70,40,20,99,90,98,88,77,66,55]) == 99)
        
    def test_avg(self):
        self.assertTrue(receiver.calculate_avg_temp_soc([93,90,94,57,63,69,70,51,85,96],[42,56,60,52,53,51,77,56,71,70])== (74.2, 65.0))
        self.assertTrue(receiver.calculate_avg_temp_soc([],[]) == "Length of the list is Zero")
        
if __name__ == '__main__':
    unittest.main()
    
    
    
    