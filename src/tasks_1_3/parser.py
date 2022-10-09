# import requests as req
from requests_tor import RequestsTor
from bs4 import BeautifulSoup
import json
import time
from tqdm import tqdm

result_json = {
    "data": []
}

req = RequestsTor()

for page in tqdm(range(41), desc="Обработано страниц"):
    url_list = f"https://hh.ru/search/vacancy?no_magic=true&L_save_area=true&text=python+%D1%80%D0%B0%D0%B7%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%87%D0%B8%D0%BA&search_field=name&salary=&currency_code=RUR&experience=doesNotMatter&order_by=relevance&search_period=0&items_on_page=20&page={page}&hhtmFrom=vacancy_search_list"
    html_list = BeautifulSoup(req.get(url_list).text, "lxml")

    a_tags = html_list.find_all(attrs={"data-qa": "serp-item__title"}) #находим все теги "а" с атрибутом data-qa="serp-item__title"

    for item in tqdm(a_tags, desc="Обработано вакансий на странице"):
        time.sleep(2)
        url_vacancy = item.attrs["href"]
        html_vacancy = BeautifulSoup(req.get(url_vacancy).text, "lxml")

        title = html_vacancy.h1.text

        work_experience = ""
        if html_vacancy.find(attrs={"data-qa": "vacancy-experience"}) is not None:
            work_experience = html_vacancy.find(attrs={"data-qa": "vacancy-experience"}).text

        salary = ""
        if html_vacancy.find(attrs={"data-qa": "vacancy-salary"}) is not None:
            salary = html_vacancy.find(attrs={"data-qa": "vacancy-salary"}).text

        region = ""
        if html_vacancy.find(attrs={"data-qa": "vacancy-view-location"}) is not None:
            region = html_vacancy.find(attrs={"data-qa": "vacancy-view-location"}).text
        elif html_vacancy.find(attrs={"data-qa": "vacancy-view-raw-address"}) is not None:
            region = html_vacancy.find(attrs={"data-qa": "vacancy-view-raw-address"}).text

        result_json["data"].append({"title": title, "work_experience": work_experience, "salary": salary, "region": region})

        with open("data.json", "w", encoding='utf8') as file:
            json.dump(result_json, file, indent=2, ensure_ascii=False)
