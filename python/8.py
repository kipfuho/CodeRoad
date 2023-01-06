import calendar
t1='Sat 02 May 2015 19:54:36 +0530'
t1=t1.split()
t2='Fri 01 May 2015 13:54:36 -0000'
t2=t2.split()
t1_time=t1[4].split(':')
t2_time=t2[4].split(':')
tz1=t1[5]
tz2=t2[5]
month_indice={'January':1,'February':2,'March':3,'April':4,'May':5,'June':6,'July':7,'August':8,'September':9,'October':10,'November':11,'December':12}
delta=calendar.timegm((int(t1[3]),month_indice[t1[2]],int(t1[1]),int(t1_time[0]),int(t1_time[1]),int(t1_time[2])))-calendar.timegm((int(t2[3]),month_indice[t2[2]],int(t2[1]),int(t2_time[0]),int(t2_time[1]),int(t2_time[2])))
print(delta)
