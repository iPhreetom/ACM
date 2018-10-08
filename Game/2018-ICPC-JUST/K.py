# -*- coding: utf-8 -*-
"""
Created on Thu Sep 27 17:43:36 2018

@author: I freedom
"""
import re

tt = int(input())
for kk in range(0,tt):

    n = int(input())
    for i in range(0,n):
        #lis = []
        dic = {}

        s = input()

        for j in range(1,9):
            s = input()
            if( j!=8 ): s = s[:-1]

            tp , val = s.split("=")

            if(tp != 'author'):
                dic[tp] = val[1:-1]
            else :
                lis = []
                namelist = val[1:-1].split(",")
                for name in namelist:
                    name = name.strip()
                    firstname , secondname = name.split(' ')
                    firstname = firstname[:2]
                    secondname = secondname[:1]
                    lis.append(firstname + '. ' + secondname)
                dic[tp] = lis
        s = input()

        #author
        first = 1
        for i in dic['author']:
            if(first == 1):
                print(i,end='')
                first = 0
            else:
                print(', '+i,end='')
        
        #title
        print('. '+dic['title'],end='')
        
        #journal
        print('. '+dic['journal'],end='')
        
        #year volume number pages
        print('. '+dic['year']+end='')
        print(';'+dic['volume']+end='')
        print('('+dic['number']+')',end='')
        print(':'+dic['pages']+'.')
        
        
        


