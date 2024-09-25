(function() {
    'use strict';

    const mainElement = document.getElementById('main');
    const mainWrapperElement = document.querySelector('.main-wrapper');

    mainElement.style.height = '100%';
    mainWrapperElement.style.height = '100%';


    const newTdElement = document.createElement('td');
    newTdElement.classList.add('planning');

    if (window.location.href === "https://intra.epitech.eu/todo") {
        newTdElement.innerHTML = '<a class="button" title="Todo" href="https://intra.epitech.eu/todo">' +
            '<img src="https://designedbynoe.files.wordpress.com/2024/01/todo_white500px.png?w=500" alt="" class="wp-image-157" style="width:60px;height:55px"/>' +
            '<span class="label">Todo</span>' +
            '</a>';
        var topBlock = document.querySelector('.bloc.top');
        var dataBlock = topBlock.querySelector('.data');
        if (dataBlock) {
            while (dataBlock.firstChild) {
                dataBlock.removeChild(dataBlock.firstChild);
            }
        }
        var mainBlock = document.querySelector('.bloc.main');
        dataBlock = mainBlock.querySelector('.data');
        if (dataBlock) {
            while (dataBlock.firstChild) {
                dataBlock.removeChild(dataBlock.firstChild);
            }
        }

        const blocMain = document.querySelector('.bloc.main');
    blocMain.innerHTML = `
        <div id="myModal" class="modal" style="display: block; height: 73vh;">
            <div class="modal-content" style="height: 100%;">
                <iframe src="http://localhost:8000" width="100%" height="100%" style="border: none;"></iframe>
            </div>
        </div>
    `;


    const modal = document.getElementById('myModal');
    modal.style.display = 'block';

    } else {
        newTdElement.innerHTML = '<a class="button" title="Todo" href="https://intra.epitech.eu/todo">' +
            '<img src="https://designedbynoe.files.wordpress.com/2024/01/todo_500px-2.png?w=500" alt="" class="wp-image-157" style="width:60px;height:55px"/>' +
            '<span class="label">Todo</span>' +
            '</a>';
    }
    const planningElement = document.querySelector('.planning');

    if (planningElement) {
        planningElement.parentNode.insertBefore(newTdElement, planningElement.nextSibling);
    } else {
        console.error('Élément avec la classe "planning" non trouvé sur la page.');
    }
})();
