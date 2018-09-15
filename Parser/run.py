import pandas as pd 
import csv

f = open('train.csv', 'rb')
reader = csv.reader(f) 

writer = csv.writer(open('trainpart.csv', 'w'))


for i in range(1000):
	for row in reader:
		writer.writerow(row)