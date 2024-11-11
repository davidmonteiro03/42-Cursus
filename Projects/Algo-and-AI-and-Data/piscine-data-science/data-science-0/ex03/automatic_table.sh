#!/bin/bash
docker exec -i postgres bash << eof
apt update
apt install -y zip unzip
rm -rf /tmp/tools/subject
unzip -d /tmp/tools /tmp/tools/subject.zip
for file in \$(find /tmp/tools/subject/customer -type f -name "*.csv" | sort); do
	table_name=\$(basename \$file ".csv")
	table_path=\$PWD\$file
	fields="event_time, event_type, product_id, price, user_id, user_session"
	query="\
TRUNCATE TABLE \$table_name;\n\
COPY \$table_name (\$fields) FROM '\$table_path' DELIMITER ',' CSV HEADER;\n"
	printf "\$query" | psql -U dcaetano -d piscineds;
done
eof
