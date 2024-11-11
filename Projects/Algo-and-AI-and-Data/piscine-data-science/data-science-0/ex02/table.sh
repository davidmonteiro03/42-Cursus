#!/bin/bash
docker exec -i postgres bash << eof
apt update
apt install -y zip unzip
rm -rf /tmp/tools/subject
unzip -d /tmp/tools /tmp/tools/subject.zip
for file in \$(find /tmp/tools/subject/customer -type f -name "*.csv" | sort); do
	table_name=\$(basename \$file ".csv")
	query="\
DROP TABLE IF EXISTS \$table_name;\n\
CREATE TABLE \$table_name(\n\
	id int NOT NULL PRIMARY KEY GENERATED ALWAYS AS IDENTITY,\n\
	event_time TIMESTAMPTZ,\n\
	event_type VARCHAR(50),\n\
	product_id INT,\n\
	price NUMERIC(10, 2),\n\
	user_id BIGINT,\n\
	user_session UUID\n\
);\n"
	printf "\$query" | psql -U dcaetano -d piscineds;
done
eof
