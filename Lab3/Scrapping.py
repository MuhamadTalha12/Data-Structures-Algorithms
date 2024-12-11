from selenium import webdriver
from bs4 import BeautifulSoup
import pandas as pd
from selenium.webdriver.chrome.service import Service
import time as sleep

# webdriver can be downloaded from
# https://sites.google.com/chromium.org/driver/downloads/versionselection?authuser=0

service = Service(
    executable_path="C:\Program Files\chromedriver-win64\chromedriver.exe"
)
options = webdriver.ChromeOptions()
driver = webdriver.Chrome(service=service, options=options)
# driver = webdriver.Chrome(executable_path='C:/Program Files/chromedriver-win64/chromedriver.exe')

products = []  # List to store name of the product
prices = []  # List to store price of the product
# ratings = []  # List to store rating of the product

driver.get("https://www.olx.com.pk/begampura_g5000006/mobile-phones_c1453")

content = driver.page_source

soup = BeautifulSoup(content, features="html.parser")
# print(soup)
for a in soup.findAll("div", attrs={"class": "b5af0448"}):
    print(a)
    name = a.find("Title", attrs={"class": "b8da62eb _1c50cf86"})
    price = a.find("span", attrs={"class": "_1f2a2b47"})
    if name != None and price != None:
        products.append(name["title"])
        prices.append(price.text)
    if len(products) == 50:
        break

df = pd.DataFrame({"Product Name": products, "Price": prices})
df.to_csv("Prd.csv", index=False, encoding="utf-8")