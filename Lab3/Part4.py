from selenium import webdriver
from bs4 import BeautifulSoup
import pandas as pd
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import time as sleep

service = Service(
    executable_path="C:\Program Files\chromedriver-win64\chromedriver.exe"
)
options = webdriver.ChromeOptions()
driver = webdriver.Chrome(service=service, options=options)

driver.get("http://eduko.spikotech.com/Course")

sleep.sleep(5)
content = driver.page_source

soup = BeautifulSoup(content, features="html.parser")

courseTitles = []
instructors =[]
semesters = []
descriptions = []
CLO1 = []
CLO2 = []
CLO3 = []
CLO4 = [] 
TextBook1 = []
TextBook2 = []
links = []

for a in soup.findAll("div", attrs={"class": "col-md-4 mb-4 d-flex align-items-stretch"}):
    
    course_name = a.find("h4",attrs={"class":"card-title"}).get_text()
    h7_names = a.findAll("h7")
    Description = a.find("p").get_text()
    instructors_name = h7_names[0].get_text()
    semester = h7_names[1].get_text()

    print(course_name,end="   ")
    print(instructors_name,end="   ")
    print(semester,end="   ")
    print(Description)

    courseTitles.append(course_name)
    instructors.append(instructors_name)
    semesters.append(semester)
    link = a.find("a").get('href')
    links.append(link)


for link in links:
    stir =  str("http://eduko.spikotech.com" + link)
    driver.get(stir)
    sleep.sleep(10)
    content = driver.page_source
    soup = BeautifulSoup(content, features="html.parser")
    data = soup.find("div",attrs={"class":"box"})
    print(data.findAll("ul"))
    crs_Description = data.find("p",attrs={"id":"CourseDescription"})
    if(crs_Description):
        descriptions.append(crs_Description.get_text())
    else:
        descriptions.append(" ")
    closUl = data.find("ul",attrs={"id":"CourseClO's"})
    clos = []
    if(closUl):
        clos = closUl.findAll("li")
    if(len(clos)>0):
        CLO1.append(clos[0].get_text())
    else:
        CLO1.append(" ")

    if(len(clos)>1):
        CLO2.append(clos[1].get_text())
    else:
        CLO2.append(" ")

    if(len(clos)>2):
        CLO3.append(clos[2].get_text())
    else:
        CLO3.append(" ")    

    if(len(clos)>3):
        CLO4.append(clos[3].get_text())
    else:
        CLO4.append(" ")
    books = []
    booksUl = data.find("ul",attrs={"id":"CourseBooks"})
    if(booksUl):
        books = booksUl.findAll("li")
        if(len(books)>0):
            TextBook1.append(books[0].find("a").get_text(strip=True))
        else:
            TextBook1.append(" ")
        
        if(len(books)>1):
            TextBook2.append(books[1].find("a").get_text(strip=True))
        else:
            TextBook2.append(" ")
    else:
        TextBook1.append(" ")
        TextBook2.append(" ")


df = pd.DataFrame({"CourseTitles": courseTitles, "Instructor": instructors,"Semester":semesters,"Description":descriptions,"CLO1":CLO1,"CLO2":CLO2,"CLO3":CLO3,"CLO4":CLO4,"TextBook1":TextBook1,"TextBook2":TextBook2})
df.to_csv("Result.csv", index=False, encoding="utf-8")