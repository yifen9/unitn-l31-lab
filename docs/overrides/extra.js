document.addEventListener("DOMContentLoaded", function () {
    const logo = document.querySelector(".md-header__button.md-logo");
    if (logo) {
      logo.setAttribute("onclick", "window.location='https://www.unitn.it';");
    }
  });