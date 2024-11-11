import datetime

time = datetime.datetime.now()
seconds = float(time.strftime("%s")) + time.microsecond / 1000000
date = time.strftime("%b %d %Y")
print(f"Seconds since January 1, 1970:"
      f" {seconds:,.4f} or {seconds:.2e}"
      f" in scientific notation")
print(f"{date}")
