from load_csv import load
import matplotlib.pyplot as plt
import numpy as np


def main():
    try:
        database_ley = load("life_expectancy_years.csv")
        database_ippqpia = \
            load("income_per_person_gdppercapita_ppp_inflation_adjusted.csv")
        data_ley = database_ley.filter(items=["1900"])
        data_ippqpia = database_ippqpia.filter(items=["1900"])
        array_ley = np.array(data_ley)
        array_ippqpia = np.array(data_ippqpia)
        plt.figure("Projection of Life Expectancy")
        plt.title("1900")
        plt.xlabel("Gross domestic product")
        plt.ylabel("Life Expectancy")
        plt.scatter(array_ippqpia, array_ley)
        plt.xscale(value="log")
        x_ticks = [300, 1000, 10000]
        x_labels = ["300", "1k", "10k"]
        plt.xticks(x_ticks, x_labels)
        plt.xlim(300)
        plt.show()
    except Exception as e:
        print(f"Exception {e}")


if __name__ == "__main__":
    main()
