"""
Created on Thu Jun 17 12:19:57 2021

@author: EPA5COB
"""

import json
import random

for i in range(10):
    print(json.dumps({"Temperature": random.randint(10,100),"SOC": random.randint(10,100)}))
    
