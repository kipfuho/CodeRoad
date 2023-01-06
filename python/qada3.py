from datetime import datetime, timedelta
class Date:
    def __init__(self, day, month, year):
        self.day = day
        self.month = month
        self.year=year
    def __init__(self):
        a=datetime.now()
        self.day=a.day
        self.month=a.month
        self.year=a.year
    def NextDay(self):
        a=datetime(self.year,self.month,self.day)+timedelta(days=1)
        self.day=a.day
        self.month=a.month
        self.year=a.year
    def __str__(self):
        return f"%MM %DD %YYYY"
a=Date()
print(a)