# Manual de buenas prácticas del IES Celia Viñas - README

This repository contains a document called "Manual de buenas prácticas digitales del IES Celia Viñas de Almería (España)".

The document is markdown formatted and is suitable to publish it by two methods:

### Method 1: Through GitHub Pages
The repository name must be the same that the GitHub username (or GitHub organization). Then, the document will be automatically published when you update it, and it can be read on the URI [github-username].github.io

### Method 2: Through pandoc
You must clone the repository on your computer or your webserver. Then, go to the root directory of your local repo and execute this command:

```
$ pandoc index.md -t html -o index.html
```

This will convert the Markdown document into a simple HTML document that can be render through a standard web browser.

If you want to create a slightly stylish HTML document, you can use a pandoc template like ***Easy Template*** (the templates must be previsouly installed on ~/.pandoc/templates directory; each template is only an HTML file):

```
$ pandoc index.md -t html -o index.html --template=easy_template.html
```

Even you can add automatically a Table of Contents (TOC):

```
$ pandoc index.md -t html -o index.html --template=easy_template.html --toc
```

Finally, you can automate the publication process on your webserver by writing a simple script that execute ***git pull*** and then execute the pandoc conversion every time you will (for example, when a cron launch the proccess)
