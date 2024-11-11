from load_image import ft_load
from pimp_image import ft_invert
from pimp_image import ft_red
from pimp_image import ft_green
from pimp_image import ft_blue
from pimp_image import ft_grey
import cv2 as ocv

array = ft_load("animal.jpeg")

ft_invert(array)
ft_red(array)
ft_green(array)
ft_blue(array)
ft_grey(array)

while True:
    if ocv.waitKey(1) & 0xFF == 27:
        break
    if ocv.getWindowProperty('Invert', ocv.WND_PROP_VISIBLE) < 1 and \
       ocv.getWindowProperty('Red', ocv.WND_PROP_VISIBLE) < 1 and \
       ocv.getWindowProperty('Green', ocv.WND_PROP_VISIBLE) < 1 and \
       ocv.getWindowProperty('Blue', ocv.WND_PROP_VISIBLE) < 1 and \
       ocv.getWindowProperty('Grey', ocv.WND_PROP_VISIBLE) < 1:
        break
ocv.destroyAllWindows()

print(ft_invert.__doc__)
