Rails.application.routes.draw do

  resources :products
  get 'como_funciona/index'
  get 'meu_perfil/index'
  get 'eu_quero/index'
  get 'meus_itens/index'

  devise_for :users
  root 'home#index'

  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
