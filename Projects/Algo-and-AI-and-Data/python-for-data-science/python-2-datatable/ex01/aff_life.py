from load_csv import load
import matplotlib.pyplot as plt
import numpy as np


def main():
    try:
        database = load("life_expectancy_years.csv")
        country = "Portugal"
        portugal_set = database[database["country"] == country]
        years = list(map(int, portugal_set.columns.drop(labels=["country"])))
        values = portugal_set.drop(columns=[
            "country"
        ]).values.flatten().tolist()
        plt.figure(f"{country} Life Expectancy")
        plt.title(f"{country} Life expectancy Projections")
        plt.xticks(np.arange(min(years), max(years) + 1, 40))
        plt.xlabel("Year")
        plt.ylabel("Life expectancy")
        plt.plot(years, values)
        plt.show()
    except Exception as e:
        print(f"Exception: {e}")


if __name__ == "__main__":
    main()
