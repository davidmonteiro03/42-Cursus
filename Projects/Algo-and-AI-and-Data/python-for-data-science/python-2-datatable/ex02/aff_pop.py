from load_csv import load
import matplotlib.pyplot as plt
import numpy as np
import math


def convert_str_to_float(value: str) -> float:
    """
    Converts a string representing a number with \
suffixes 'B', 'M', or 'k' to a float.

    Args:
        value (str): A string representing a number,
potentially ending with \
'B' for billions, 'M' for millions, or 'k' for thousands.

    Raises:
        Exception: If any other exception occurs during conversion.

    Returns:
        float: The numeric value represented by the string.
    """
    if value.endswith("B"):
        try:
            return float(value[:-1]) * 1e9
        except Exception as e:
            raise e
    elif value.endswith("M"):
        try:
            return float(value[:-1]) * 1e6
        except Exception as e:
            raise e
    elif value.endswith("k"):
        try:
            return float(value[:-1]) * 1e3
        except Exception as e:
            raise e
    try:
        return float(value)
    except Exception as e:
        raise e


def main():
    try:
        country1 = "Belgium"
        country2 = "France"
        database = load("population_total.csv")
        data1 = database[
            database["country"] == country1
        ].drop(columns=["country"])
        data2 = database[
            database["country"] == country2
        ].drop(columns=["country"])
        filter1 = data1.loc[:, (data1.columns >= "1800") &
                            (data1.columns <= "2050")]
        filter2 = data2.loc[:, (data2.columns >= "1800") &
                            (data2.columns <= "2050")]
        years = filter1.columns.values.astype(int)
        values1 = filter1.values.flatten()
        values2 = filter2.values.flatten()
        values1 = [convert_str_to_float(num) for num in values1]
        values2 = [convert_str_to_float(num) for num in values2]
        plt.figure("Population Projections")
        plt.title("Population Projections")
        plt.xlabel("Year")
        plt.ylabel("Population")
        max_value = max(max(values1), max(values2))
        if max_value < 10e3:
            dec, c = 1, ''
        elif max_value < 10e6:
            dec, c = 1e3, 'k'
        elif max_value < 10e9:
            dec, c = 1e6, 'M'
        else:
            dec, c = 1e9, 'B'
        step = math.ceil(max_value / (50 * dec)) * (10 * dec)
        yticks = np.arange(0, max_value + step, step)
        yticks = [tick for tick in yticks if tick > 0]
        ylabels = [f"{tick / dec:.0f}{c}" for tick in yticks]
        xticks = np.arange(min(years), max(years) + 1, 40)
        plt.xticks(xticks)
        plt.yticks(yticks, ylabels)
        plt.plot(years, np.array(values1), label=country1, color="steelblue")
        plt.plot(years, np.array(values2), label=country2, color="green")
        plt.legend(loc="lower right")
        plt.show()
    except Exception as e:
        print(f"Exception: {e}")


if __name__ == "__main__":
    main()
