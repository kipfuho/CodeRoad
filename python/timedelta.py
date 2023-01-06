from datetime import datetime as dt
format="%a %d %b %Y %H:%M:%S %z"
for _ in range(int(input())):
    print(abs(int((dt.strptime(input(),format)-dt.strptime(input(),format)).total_seconds())))