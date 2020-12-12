import time #for giving the script a little break
from selenium import webdriver 
from selenium.webdriver.common.keys import Keys

url = 'https://us02web.zoom.us/meeting/register/tZcsdu2grj0rGdGbloMfJkm3COU7Lgb81gjp'

class EntraZoom:
    def __init__(self, word):
        self.url = url #the site we are going to be scraping
        self.driver = webdriver.Chrome()
        self.driver.get(self.url)
        
        self.time_break(15)
        
        