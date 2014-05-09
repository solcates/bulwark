test: deps
	@rm -f nss-debug.log
	@$(PREFIX) node --expose-gc ./node_modules/.bin/lab -m 60000 -v

cover: deps
	@rm -f nss-debug.log cover.html
	@$(PREFIX) node --expose-gc ./node_modules/.bin/lab -m 60000 -s -c -r html -o cover.html

docs: deps
	@echo -n Generating docs...
	@rm -rf docs
	@./node_modules/.bin/jsdoc -r -d docs lib README.md
	@echo " done!"

rebuild:
	npm install

deps:
	@if [ ! -d node_modules ]; then \
		echo "Installing dependencies.."; \
		npm install --silent; \
	fi

.PHONY: test cover docs rebuild deps