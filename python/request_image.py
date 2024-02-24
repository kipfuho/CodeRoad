import requests
import time
def download(fileName):
    f = open(fileName,'wb')
    f.write(requests.get('https://thispersondoesnotexist.com/', headers={'User-Agent': 'My User Agent 1.0'}).content)
    f.close()


path = 'D:/fake/'
for i in range(31329, 40000):
    download(path + str(i) + '.jpg')
    print(i)
    time.sleep(1)
    