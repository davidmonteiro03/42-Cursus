import pandas as pd


def load(path: str) -> pd.DataFrame:
    """Loads a CSV file into a pandas DataFrame.

    Args:
        path (str): The file path to the CSV file.

    Returns:
        pd.DataFrame: The loaded DataFrame if successful, None otherwise.
    """
    try:
        return pd.read_csv(filepath_or_buffer=path)
    except Exception as e:
        print(f"Exception: {e}")
        return None
