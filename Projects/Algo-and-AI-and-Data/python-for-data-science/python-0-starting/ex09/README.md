# ft_package

## Build
<pre>python3 -m build</pre>

## Install
<pre>pip install ./dist/ft_package-0.0.1.tar.gz</pre>
or
<pre>pip install ./dist/ft_package-0.0.1-py3-none-any.whl</pre>

## Example usage
<pre>python3 tester.py</pre>

## Details
<pre>pip show -v ft_package</pre>

## Uninstall
<pre>pip uninstall -y ft_package</pre>

## Clean
<pre>
find * -name "__pycache__" -exec rm -rf {} 2>/dev/null \;
rm -rf dist
</pre>
